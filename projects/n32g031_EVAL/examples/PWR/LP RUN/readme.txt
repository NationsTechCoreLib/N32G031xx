1、功能说明
    1、LP RUN模式的进入和退出。


2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031C8L7-STB V1.0     


3、使用说明

    系统配置；
        1、时钟源：HSE+PLL/LSE
        2、时钟频率：48M/4M


    使用方法：
        在KEIL下编译后烧录到评估板，串接电流表，上电后过一会，电流明显变小。又过一会电流又变大。
        循环往复，查看打印信息可以看到进入和退出LP RUN模式。
            


4、注意事项
    当进入LP RUN模式时，系统时钟切换到了LSE/LSI，当退出时，需要切回用户默认系统时钟


1. Function description
    1. Entry and exit of LP RUN mode.


2. Use environment

    /* Software development environment: the name and version number of the software tool used in the current project */
    IDE tool: KEIL MDK-ARM 5.21.1.0
      
    /* Hardware environment: the development hardware platform corresponding to the project */
    Development board: N32G031C8L7-STB V1.0


3. Instructions for use

    System Configuration;
        1. Clock source: HSE+PLL/LSE
        2. Clock frequency: 48M/4M


    Instructions:
        After compiling under KEIL, it is burned to the evaluation board, and the ammeter is connected in series. After a while, the current becomes significantly smaller. After a while the current increases again.
        Cycle back and forth, check the print information to see entering and exiting the LP RUN mode.
            


4. Matters needing attention
    When entering LP RUN mode, the system clock is switched to LSE/LSI, and when exiting, it needs to switch back to the user default system clock

