1、功能说明
    1、SPI 全双工软件 NSS 模式发送接收数据
2、使用环境
     软件开发环境：KEIL MDK-ARM 5.30.0.0
     硬件环境：      基于N32G031CL-STB V1.0开发
3、使用说明
     系统配置：
         1、SystemClock：48MHz
         2、GPIO：SPI1: SCK--PA5、 MISO--PA6、 MOSI--PA7
                         SPI2: SCK--PB13、MISO--PB14、MOSI--PB15
     使用方法：
        1、编译后下载程序复位运行；
        2、SPI1 初始化为主机，发送数据，SPI2 初始化为从机，接收数据 ，传输完成后，检查数据，查看 TransferStatus1 和 TransferStatus2 状态为 PASSED，
             SPI2 初始化为主机，发送数据，SPI1 初始化为从机，接收数据 ，传输完成后，检查数据，查看 TransferStatus3 和 TransferStatus4 状态为 PASSED；
4、注意事项
     无

1. Function description
    1. SPI full duplex software NSS mode to send and receive data
2. Use environment
    Software development environment: KEIL MDK-ARM 5.30.0.0
    Hardware Environment: Developed based on N32G031CL-STB V1.0
3. Instructions for use
    System Configuration;
        1. SystemClock：48MHz
        2. GPIO：SPI1: SCK--PA5,   MISO--PA6,  MOSI--PA7
                       SPI2: SCK--PB13, MISO--PB14, MOSI--PB15
    Instructions:
        1. After compiling, download the program to reset and run;
        2. SPI1 is initialized as a master, sending data, SPI2 is initialized as a slave, receiving data, after the transmission is completed, 
           check the data, and check that the status of TransferStatus1 and TransferStatus2 is PASSED；
           SPI2 is initialized as a master, sending data, SPI1 is initialized as a slave, receiving data, after the transmission is completed, 
           check the data, and check that the status of TransferStatus3 and TransferStatus4 is PASSED;
4. Matters needing attention
    No