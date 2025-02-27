# Firmware Mapping Note for v.poly.1.0.B.hex

This firmware is specifically designed for Polymega use and supports two mapping modes—**"+ mode" (Digital mode)** and **"O mode" (Non-Digital mode)**—to meet Polymega’s unique controller requirements for certain fighting games.

## + Mode (Digital Mode)
In this mode (when the digital flag is true), the mapping is as follows:

- **A button:** Taken directly from the physical A input.
- **X button:** Taken directly from the physical X input.
- **B button:** Taken directly from the physical B input.
- **LB:** Mapped from the physical Z input.
- **RB:** Mapped from the physical C input.

## O Mode (Non-Digital Mode)
In this mode (when the digital flag is false), the mapping is modified to match Polymega’s layout:

- **A button:** Remapped from the physical B input.
- **X button:** Remapped from the physical A input.
- **B button:** Remapped from the physical C input.
- **LB:** Remapped from the physical X input.
- **RB:** Remapped from the physical Z input.

For standard operation with default button assignments, please use firmware version **v.poly.1.0.0.hex**.
