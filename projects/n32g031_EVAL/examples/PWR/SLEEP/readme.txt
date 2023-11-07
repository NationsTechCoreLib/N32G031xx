1、功能说明
    SLEEP进入和唤醒退出示例。


2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031C8L7-STB V1.0     



3、使用说明

    系统配置；
        1、时钟源：HSE+PLL

    使用方法：
        在KEIL下编译后烧录到评估板，上电输出打印“PWR_SLEEP INIT”。过了一会输出打印“Lower Power Entry”，表明进入SLEEP了。
        按下WAKEUP按键后，串口又输出“Lower Power Entry”，表明MCU唤醒之后又开始进入SLEEP模式。


4、注意事项
    无


1. Function description
    Example of SLEEP entry and wake-up exit.


2. Use environment

    /* Software development environment: the name and version number of the software tool used in the current project */
    IDE tool: KEIL MDK-ARM 5.21.1.0
      
    /* Hardware environment: the development hardware platform corresponding to the project */
    Development board: N32G031C8L7-STB V1.0



3. Instructions for use

    System Configuration;
        1. Clock source: HSE+PLL

    Instructions:
        After compiling under KEIL and burning it to the evaluation board, the output prints "PWR_SLEEP INIT" after power-on. After a while, the output prints "Lower Power Entry", indicating that it has entered SLEEP.
        After pressing the WAKEUP button, the serial port outputs "Lower Power Entry" again, indicating that the MCU starts to enter the SLEEP mode after waking up.


4. Matters needing attention
    none
