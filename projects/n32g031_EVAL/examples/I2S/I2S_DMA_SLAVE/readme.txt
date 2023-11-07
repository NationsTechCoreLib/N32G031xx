1、功能说明
     1、I2S 从模式通过 DMA 收发数据
2、使用环境
     软件开发环境：KEIL MDK-ARM 5.30.0.0
     硬件环境：    基于N32G031CL-STB V1.0开发
3、使用说明
     系统配置：
         1、SystemClock：48MHz
         2、GPIO：（主模式 DEMO 板）I2S1: WS--PA4、CK--PA5、SD--PA7
                         （从模式 DEMO 板）I2S1: WS--PA4、CK--PA5、SD--PA7
         3、DMA：I2S1 发送采用 DMA_CH3 通道，I2S1 接收采用 DMA_CH2 通道；
         4、日志打印：从模式 DEMO 板 PA9(TX)，波特率：115200
     使用方法：
         1、编译后下载程序复位运行；
         2、主模式 DEMO 板和从模式 DEMO 板PA4,PA5,PA7连接好后，从模式 DEMO 板连接串口打印工具，上电，
              先按住主模式 DEMO 板复位键不松，再按下从模式 DEMO 板的复位键，从模式 DEMO 板跑起来后再松开主模式 DEMO 板的复位键，查看打印测试成功；
4、注意事项
     需要两块 demo 板配合，一块板子烧录主模式程序，一块板子烧录从模式程序，连接两块板子的 VCC 和 GND

1. Function description
    1. I2S slave mode to send and receive data through DMA
2. Use environment
    Software development environment: KEIL MDK-ARM 5.30.0.0
    Hardware Environment: Developed based on N32G031CL-STB V1.0
3. Instructions for use
    System Configuration;
        1. SystemClock：48MHz
        2. GPIO：(Master mode DEMO board) I2S1: WS--PA4, CK--PA5, SD--PA7
                       (Slave mode DEMO board)    I2S1: WS--PA4, CK--PA5, SD--PA7
        3. DMA: I2S1 transmission adopts DMA_CH3 channel, I2S1 reception adopts DMA_CH2 channel;
        4. Log print: slave mode DEMO board PA9(TX), baud rate: 115200
    Instructions:
        1. After compiling, download the program to reset and run;
        2. After the master mode DEMO board and slave mode DEMO board PA4, PA5, PA7 are connected, 
           the slave mode DEMO board is connected to the serial port printing tool, power on, 
           first press and hold the master mode DEMO board reset button, and then press the slave mode DEMO board reset button, 
           after the slave mode DEMO board has run, release the reset button of the master mode DEMO board and then check the printing test is successful;
4. Matters needing attention
    Two demo boards are required, one board to burn the master mode program, one board to burn the slave mode program, connect the VCC and GND of the two boards