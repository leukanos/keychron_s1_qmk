# Keyboard parity: Keychron S1 and MacBook

The Keychron S1 keymap (`keymap.c`) is the baseline. Karabiner (`karabiner/karabiner.json`) makes the MacBook built-in keyboard follow it. Karabiner ignores the Keychron.

## Caps key

- Tap: Esc.
- Hold: the `MOD` layer on the Keychron. Hyper on the MacBook, rewritten by Karabiner rules.
- Tap window: 200 ms on both. Holding and pressing another key starts the hold at once.

## MOD layer

| Keys | Result | With Left Cmd | With Left Ctrl | With Left Shift |
|---|---|---|---|---|
| H J K L | Left, Down, Up, Right | Shift+arrow | Ctrl+arrow | H: Ctrl+Shift+Tab, J: Cmd+Tab, K: Cmd+Shift+Tab, L: Ctrl+Tab |
| U O P `;` | Home, End, Page Up, Page Down | Shift+key | | |
| Z X C V B D R T | Ctrl+key | | | |
| N | Opt+Backspace | Cmd+Backspace | | |
| M | Backspace | Cmd+Backspace | | |
| `,` | Delete | | | |
| `.` | Opt+Delete | | | |
| Every other key | Hyper+key | | | |

Left Opt with H or L jumps by word (Opt+Left, Opt+Right). On the Keychron the layer passes Opt through. On the MacBook, two Karabiner rules do this. Opt+Shift word selection is not available on the layer, because the Shift overrides take H and L.

Hyper is Cmd+Ctrl+Opt+Shift. The Keychron sends the left-side modifiers. Karabiner sends the right-side modifiers.

## Other shared behavior

- Left Shift tap: `(`. Right Shift tap: `)`.
- Grave double tap: `~`.
- Key after Space: Right Opt. The MacBook remaps Right Cmd to Right Opt.

## Exceptions

- Esc double tap sends Caps Lock on the Keychron only. Karabiner cannot undo the first Esc.
- The Keychron has dedicated Home, End, Page Up, and Page Down keys. The MacBook does not.
- The Keychron key after F12 (screenshot icon) sends F13 on the Mac layer. The MacBook has no such key.
- The Windows layers have no `MOD` layer or tap dance.
- Function row: the Keychron sends F1 to F12 by default. `Fn+F3` is Mission Control and `Fn+F4` is Launchpad. The MacBook sends media keys by default unless macOS standard function keys is on (`defaults write -g com.apple.keyboard.fnState -bool true`, then log out and in).

## Build and flash

1. `./build.sh` copies the keymap into `~/code/qmk_firmware` and builds in Docker. The result is `~/code/qmk_firmware/keychron_s1_ansi_rgb_leukanos.bin`.
2. Unplug the keyboard. Hold Esc and plug it in. The keyboard enters the bootloader.
3. Flash the `.bin` with QMK Toolbox or `dfu-util`.

The S1 rgb variant has PID `0x0410`. The white variant has PID `0x0411` and needs its own Karabiner ignore entry.

## Sync Karabiner

Karabiner reads `~/.config/karabiner/karabiner.json`. Copy this repo's file over it to apply changes. Copy it back here after any change in the Karabiner app.

## Test checklist

Run on the Keychron and on the MacBook. Use Karabiner EventViewer to see the keys.

- Caps tap sends Esc. Caps hold with a fast H sends Left, not Esc.
- Each key in the `MOD` table, with and without Cmd, Ctrl, and Shift.
- Caps+Left Opt+H and Caps+Left Opt+L jump by word.
- Caps+S fires a test Hyper hotkey.
- Shift taps send `(` and `)`. Left Shift held still works as Shift.
- Grave double tap gives `~`. A single tap gives a grave.
- The key after Space sends Option.
- Keychron only: Esc double tap toggles Caps Lock. `Fn+F3` and `Fn+F4` work.
