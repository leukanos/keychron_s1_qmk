#!/bin/sh
# Copy the keymap into a QMK checkout and build it in Docker.
# The qmkfm image comes from Docker Hub. The ghcr.io/qmk/qmk_cli image denies pulls.
set -e

QMK_HOME="${QMK_HOME:-$HOME/code/qmk_firmware}"
KEYMAP_DIR="$QMK_HOME/keyboards/keychron/s1/ansi/rgb/keymaps/leukanos"
HERE="$(cd "$(dirname "$0")" && pwd)"

mkdir -p "$KEYMAP_DIR"
cp "$HERE/keymap.c" "$HERE/rules.mk" "$HERE/config.h" "$KEYMAP_DIR/"

docker run --rm --user "$(id -u):$(id -g)" -w /qmk_firmware \
    -v "$QMK_HOME":/qmk_firmware:z \
    -e SKIP_GIT=1 -e SKIP_VERSION=1 \
    qmkfm/qmk_cli make keychron/s1/ansi/rgb:leukanos

echo "Firmware: $QMK_HOME/keychron_s1_ansi_rgb_leukanos.bin"
