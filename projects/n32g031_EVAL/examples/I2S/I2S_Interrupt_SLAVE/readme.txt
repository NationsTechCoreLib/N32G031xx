1、功能说明
     1、I2S 从模式通过中断接收数据
2、使用环境
     软件开发环境：KEIL MDK-ARM 5.30.0.0
     硬件环境：基于N32G031CL-STB V1.0开发
3、使用说明
     系统配置：
         1、SystemClock：48MHz
         2、GPIO：（主模式 DEMO 板）I2S1: WS--PA4、CK--PA5、SD--PA7
                  （从模式 DEMO 板）I2S1: WS--PA4、CK--PA5、SD--PA7
         3、中断：I2S1 中断入口函数 SPI1_IRQHandler
     使用方法：
         1、编译后下载程序复位运行；
         2、从模式 DEMO 板进入调试模式，先按住主模式 DEMO 板复位键，然后从模式 DEMO 板全速跑，
              再松开主模式 DEMO 板复位键，查看 TransferStatus1 和 TransferStatus2 状态为 PASSED
4、注意事项
     需要两块 demo 板配合，一块板子烧录主模式程序，一块板子烧录从模式程序，连接两块板子的 VCC 和 GND

1. Function description
    1. I2S slave mode receives data via interrupt
2. Use environment
    Software development environment: KEIL MDK-ARM 5.30.0.0
    Hardware Environment: Developed based on N32G031CL-STB V1.0
3. Instructions for use
    System Configuration;
        1. SystemClock：48MHz
        2. GPIO：(Master mode DEMO board) I2S1: WS--PA4, CK--PA5, SD--PA7
                 (Slave mode DEMO board)  I2S1: WS--PA4, CK--PA5, SD--PA7
        3. Interrupt: I2S1 interrupt entry function SPI1_IRQHandler
    Instructions:
        1. After compiling, download the program to reset and run;
        2. The slave mode DEMO board enters the debug mode, first press and hold the master mode DEMO board reset button, then the slave mode DEMO board runs at full speed,
           then release the reset button of the master mode DEMO board, and check that the status of TransferStatus1 and TransferStatus2 is PASSED
4. Matters needing attention
    Two demo boards are required, one board to burn the master mode program, one board to burn the slave mode program, connect the VCC and GND of the two boards