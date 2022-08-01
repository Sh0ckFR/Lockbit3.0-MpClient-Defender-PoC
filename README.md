# Lockbit3.0-MpClient-Defender-PoC
Lockbit3.0 Microsoft Defender MpClient.dll DLL Hijacking PoC

Based on: LockBit ransomware abuses Windows Defender to load Cobalt Strike

https://www.bleepingcomputer.com/news/security/lockbit-ransomware-abuses-windows-defender-to-load-cobalt-strike/

## How to test by yourself

* Create a new directory, copy `C:\Program Files\Windows Defender\MpCmdRun.exe` or `C:\Program Files\Windows Defender\NisSrv.exe` in this new directory
* Copy `mpclient-mpcmdrun.dll` or `mpclient-nissrv.dll` (depends of the binary that you want to test) and rename the dll `mpclient.dll`.
* Run the executable.

## How to compile

* Install https://releases.llvm.org/download.html
* Reboot your computer

If you want to try MpCmdRun.exe:
```
clang++ dllmain-mpcmdrun.cpp -o mpclient.dll -shared
```

If you want to try NisSrv.exe:
```
clang++ dllmain-NisSrv.cpp -o mpclient.dll -shared
```
