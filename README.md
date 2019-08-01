# mping-win
A mping on Windows command, targets multiple IP addresses

#1. Download Zip file

#2 Unzip

#3 Run > mping \<IPaddress1\> \<IPaddress2\> ...

Example ------------------------------------
```
C:\>mping 192.168.1.1 192.168.1.18 192.168.1.2

  Fri Mar 23 00:42:51 2018
     192.168.1.1    192.168.1.18     192.168.1.2
               0               0               0 <- NG out of 156
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms            <1ms
            <1ms            <1ms      *** NG ***
  Fri Mar 23 00:43:09 2018
     192.168.1.1    192.168.1.18     192.168.1.2
               0               0               1 <- NG out of 168
            <1ms            <1ms      *** NG ***
            <1ms            <1ms      *** NG ***
```
