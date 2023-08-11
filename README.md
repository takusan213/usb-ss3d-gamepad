# usb-ss3d-gamepad
This project remakes your SEGA Multi Controller (aka 3D Control Pad in US) into a usb gamepad.
Let's play retro games as well as recent games distributed on Steam with your USB Multi Controller!   

日本語のサポートページはこちら:crossed_flags:  
https://geekyfab.com/support_ss3d_gamepad  
You can read more details there.   

# Demo
[!['USB SEGA Multicontroller Demo']('https://github.com/takusan213/usb-ss3d-gamepad/assets/78714269/0061b51e-b496-4016-aa5c-1cd539da3a73')]('https://www.youtube.com/watch?v=o0ukZ1JmDkk')

# Features
In this project, I share circuit and firmware.  
You can edit the source code of the firmware as you wish and write it to the USB unit.  

# Tested OS / hardware
- Windows 10
- Windows 11
- Raspberry PI 3
    - Raspberry Pi OS 
    - Recalbox for RASPBERRY PI 3
    - RetroPi 4.7.1 for RASPBERRY PI 2/3
- Raspberry PI 4
    - Raspberry Pi OS
    - Recalbox for RASPBERRY PI 4/400
    - RetroPie 4.7.1 for RASPBERRY PI 4/400
- Retro Freak

# Usage
## Normal mode
1. Attach this product to your SEGA Multi Controller.
2. Connect this product to your PC or others with an USB cable. 

## Firmware write mode
1. Dettach this product from your SEGA Multi Controller.
2. Connect this product to your PC with an USB cable.

## Windows
In a Windows environment, USB SS Gamepad runs with standard driver.  
You don't need to install additional drivers.  

## Raspberry PI OS
In a Raspberry PI OS environment, you need to install 'joystick' package like this
```bash
sudo apt install joystick
```
It is also good to install 'jstest-gtk' for operation test.
```bash
sudo apt install jstest-gtk
```

## Recalbox and RetroPie
In Recalbox and RetroPie, you don't need to install 'joystick' package.  
Maybe Recalbox and RetroPie install it automatically.

# Author
* Takusan = [GEEKY Fab.](geekyfab.com)  
