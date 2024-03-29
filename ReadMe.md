![](https://github.com/SuWeipeng/img/raw/master/13_car/firedragon_rc.jpg)       
软件介绍
---
> 使用STM32F103C8单片机。        
> 软件高度可移植，原则上各个软件模块 STM32 全系列通用(只要有足够目标模块使用的Flash和RAM既可)。

1. 【编程语言】使用 C/C++ 混合编程；
2. 【无线通信】使用 Mavlink 通信协议；
3. 【RTOS系统】使用 RT-Thread 实时操作系统，裸机代码 **[点此链接](https://github.com/SuWeipeng/firedragon_rc)**；      
4. 【虚拟串口】使用 RT-Thread 虚拟串口，使用 CubeMX 内的第三方虚拟串口的代码 **[点此链接](https://github.com/SuWeipeng/firedragon_rc)**；
5. 【nRF24L01】使用 RT-Thread 软件包驱动，使用可以在 STM32 全系列单片机上使用的**裸机驱动**的代码 **[点此链接](https://github.com/SuWeipeng/firedragon_rc)**。

怎样编译
---
> MDK5、IAR、GCC 三平台通用代码。<br>
> Sugar 只维护配置文件，不维护工程。<br>
> 因为：不同平台的工程可按配置自动生成，方法如下：

1. [一招通吃MDK5、IAR、GCC](https://mp.weixin.qq.com/s/aPUbSAndjvs4CaPj3CFsJg)
2. [【升级】一招通吃MDK5、IAR、GCC](https://mp.weixin.qq.com/s/iVmaQ3S4vcitbJ8iXZyArw)

一、MDK5 下编译设置       
![](https://github.com/SuWeipeng/img/raw/master/13_car/mdk5_rtt_compile.jpg)

二、IAR 下的设置（以使用 JLink 调试为例）
![](https://github.com/SuWeipeng/img/raw/master/13_car/iar_rtt_compile.jpg)

教程推文
---
> 欢迎关注微信公众号：MultiMCU EDU<br>
> ![](https://github.com/SuWeipeng/img/raw/master/17_wechat/08cm.jpg)

1. [马达驱动](https://mp.weixin.qq.com/s/7Bk-xQbymZaez4g5sUALxw)
2. [物联网通信，如何应用 mavlink 通信协议](https://mp.weixin.qq.com/s/K92U5lO0KGM4mUzyGSXvcg)
3. [让车听遥控的话](https://mp.weixin.qq.com/s/h7FURP4kGNTJmfsHatk-4A)
4. [看完这篇一定能会用 ab 相编码器](https://mp.weixin.qq.com/s/aUa0sHmGF6CbPej6O9IzKQ)
5. [PID 调参](https://mp.weixin.qq.com/s/TO926HglAhvM9RNe-2kJuQ)

