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

## pyserial
`python -m serial.tools.list_ports` lists available ports

* `Serial.name`: device name

### finding out information about USB devices before connecting
Use the serial.tools.list_ports module
```python
from serial.tools import list_ports
ports=list_ports.comports()
for port in ports:
  print("device path\t"+port.device)
  print("vendor id:\t"+str(port.vid))
  print("product id:\t"+str(port.pid))
  print("product:\t"+str(port.product))
  print("manufacturer:\t"+str(port.manufacturer))
  print("serial number:\t"+str(port.serial_number))
  print("description:\t"+str(port.description))
  print("hwid:\t"+str(port.hwid))
  print("interface:\t"+str(port.interface))
  print("location:\t"+str(port.location))
```

*does connecting to serial port require sudo???*

* [pyserial overview](https://pythonhosted.org/pyserial/pyserial.html#overview)
* [pyserial tools](http://pyserial.readthedocs.io/en/latest/tools.html)

## /dev directory
location of device files. Everything is a file, in UNIX.

# screen command
*screen* command lets you connect to /dev device(by using the special file to a serial device), like `sudo screen /dev/ttyUSB0 38400`. *ctrl-a k* to quit.

screen command is actually a **terminal multiplexer**- more about that in */Terminal stuff*.

# polling
Polling is the process where the computer or controlling device waits for an external device to check for its readiness or state, often with low-level hardware.
 
# connecting to serial in C++
see ublox repository

# [serial terminal basics](https://learn.sparkfun.com/tutorials/terminal-basics/all#connecting-to-your-device)- sparkfun

# serial monitor
[Minicom](https://elinux.org/Minicom) seems the most useful (can display in both ASCII and hex). Launch `minicom -s`, and if you want line wrapping on, `minicom -s -w`.


# references
* [boost::asio::serial_io::read](https://www.boost.org/doc/libs/1_69_0/doc/html/boost_asio/reference/read.html)
* [boost::asio::serial_io::async_read_some](https://www.boost.org/doc/libs/1_69_0/doc/html/boost_asio/reference/serial_port/async_read_some.html)
* [boost::asio::serial_port で ZigBee と会話してみた](http://tips.hecomi.com/entry/20120728/1343504831)
* [Boost.Asio で read / async_read を使用する際の注意点](http://amedama1x1.hatenablog.com/entry/2014/06/16/210600)
* [【Boost】シリアル通信](http://blog.livedoor.jp/k_yon/archives/52145222.html)
