# usb-ss3d-gamepad
This project remakes your SEGA Multi Controller (aka 3D Control Pad in US) into a usb gamepad.
Let's play retro games as well as recent games distributed on Steam with your USB Multi Controller!   

日本語のサポートページはこちら:crossed_flags:  
https://geekyfab.com/support_ss3d_gamepad  
You can read more details there.   

# Demo
[![USB SEGA Multicontroller Demo](https://private-user-images.githubusercontent.com/78714269/261855793-95570b60-6f9e-4da2-9e6b-d4bfd5d97a90.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTEiLCJleHAiOjE2OTI1MzkzOTIsIm5iZiI6MTY5MjUzOTA5MiwicGF0aCI6Ii83ODcxNDI2OS8yNjE4NTU3OTMtOTU1NzBiNjAtNmY5ZS00ZGEyLTllNmItZDRiZmQ1ZDk3YTkwLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFJV05KWUFYNENTVkVINTNBJTJGMjAyMzA4MjAlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjMwODIwVDEzNDQ1MlomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPTkzMzJlMzlhY2ViNGE2MjMxNDYxZWY4NmQzZmEyY2M4ZTM2MTNiNWJjMjQyODA3YzMzNzI2ZmU3YWRiODQ4ODcmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JmFjdG9yX2lkPTAma2V5X2lkPTAmcmVwb19pZD0wIn0.8FLVte5skHQOYvQi3AL9zNIUyAOX83MXaqHHyoH3LE4)](https://youtu.be/o0ukZ1JmDkk)

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
