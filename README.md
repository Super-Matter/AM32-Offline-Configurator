# AM32 Offline Configurator

A Qt Widgets desktop application for configuring and updating AM32 electronic speed controllers (ESCs) without using the web configurator. The current app identifies itself as Config Tool 1.98 and targets AM32 firmware 2.21 and newer.

## Fork-specific changes

This is a fork of [am32-firmware/Offline-Configurator](https://github.com/am32-firmware/Offline-Configurator). Compared with the upstream v1.97 base, this fork focuses on desktop usability and macOS distribution:

- Adds a **Refresh Ports** button and preserves the selected serial port when the detected-port list changes.
- Uses AM32-branded application icons and larger macOS UI text/scaling defaults.
- Publishes separate Apple Silicon and universal macOS packages.

The AM32 configuration and firmware communication behavior remains based on upstream; this fork does not provide or modify ESC firmware.

## macOS downloads

Download either disk image from the [Releases page](https://github.com/Super-Matter/AM32-Offline-Configurator/releases):

- **Apple Silicon (arm64):** `SerialPortConnector-macOS-arm64.dmg`. Choose this for an M-series Mac.
- **Universal:** `SerialPortConnector-macOS-universal.dmg`. Supports both Intel (`x86_64`) and Apple Silicon (`arm64`) Macs.

The release builds target macOS 13 or newer. Open the DMG and drag **SerialPortConnector.app** to **Applications**. CI builds are ad-hoc signed but not notarized, so macOS may show a Gatekeeper warning on first launch. Only bypass it if you trust the release source.

## Basic use

1. Connect the ESC through a supported USB/serial interface.
2. Select its port and click **Connect**.
3. Use the configuration and firmware tools as needed. Load or save a configuration file from the main screen.
4. Disconnect before refreshing the port list; click **Refresh Ports** to rescan.

Always select firmware intended for the exact ESC target and follow the hardware manufacturer's safety guidance. Motors can start unexpectedly during configuration or testing.

## Building

The macOS release workflow uses Qt 6.10.3 with the Qt SerialPort module and Xcode's Clang toolchain. See [`.github/workflows/build.yml`](.github/workflows/build.yml) for the reproducible build and packaging commands. The universal app is made from separate arm64 and x86_64 builds and verified with `lipo` before packaging.
