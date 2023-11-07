1、功能说明
    1、PVD配置电压产生对应的中断。


2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031C8L7-STB V1.0     


3、使用说明

    系统配置；
        1、时钟源：HSE+PLL

    使用方法：
        在KEIL下编译后烧录到评估板，通过仿真器进入调试模式，在PVD_IRQHandler()中设置断点。
        全速运行。然后再把电压调到PVD设置电压附近，此时程序会停在断点处。


4、注意事项
    无


1. Function description
    1. The PVD configuration voltage generates a corresponding interrupt.


2. Use environment

    /* Software development environment: the name and version number of the software tool used in the current project */
    IDE tool: KEIL MDK-ARM 5.21.1.0
      
    /* Hardware environment: the development hardware platform corresponding to the project */
    Development board: N32G031C8L7-STB V1.0


3. Instructions for use

    System Configuration;
        1. Clock source: HSE+PLL

    Instructions:
        After compiling under KEIL, burn it to the evaluation board, enter the debug mode through the emulator, and set a breakpoint in PVD_IRQHandler().
        Running at full speed. Then adjust the voltage to the vicinity of the PVD setting voltage, and the program will stop at the breakpoint at this time.


4. Matters needing attention
    none

