# USB devices

## How to identify a device
The 4 first hexadecimal digits are the Vendor ID (04b3 = IBM).

The 4 last hexadecimal digits are the Device ID (3108 = ThinkPad 800dpi Optical Travel Mouse).

`lsusb` lists the devices

`lsusb -t` to view tree
```
/:  Bus 03.Port 1: Dev 1, Class=root_hub, Driver=xhci_hcd/4p, 5000M
/:  Bus 02.Port 1: Dev 1, Class=root_hub, Driver=xhci_hcd/9p, 480M
    |__ Port 1: Dev 5, If 0, Class=Imaging, Driver=, 480M
    |__ Port 1: Dev 5, If 1, Class=Vendor Specific Class, Driver=usbfs, 480M
    |__ Port 1: Dev 5, If 2, Class=Vendor Specific Class, Driver=ipheth, 480M
    |__ Port 6: Dev 2, If 0, Class=Vendor Specific Class, Driver=, 12M
    |__ Port 7: Dev 3, If 1, Class=Wireless, Driver=btusb, 12M
    |__ Port 7: Dev 3, If 0, Class=Wireless, Driver=btusb, 12M
    |__ Port 8: Dev 4, If 1, Class=Video, Driver=uvcvideo, 480M
    |__ Port 8: Dev 4, If 0, Class=Video, Driver=uvcvideo, 480M
/:  Bus 01.Port 1: Dev 1, Class=root_hub, Driver=ehci-pci/3p, 480M
    |__ Port 1: Dev 2, If 0, Class=Hub, Driver=hub/8p, 480M
        |__ Port 5: Dev 3, If 0, Class=Human Interface Device, Driver=usbhid, 12M

```
* [HowToIdentifyADeviceUSB](https://wiki.debian.org/HowToIdentifyADevice/USB)
* [Linu x の USB -Qiita](https://qiita.com/propella/items/66eb1e93cc71ebea3829)
