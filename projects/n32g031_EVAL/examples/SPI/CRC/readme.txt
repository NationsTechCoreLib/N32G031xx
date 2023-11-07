1、功能说明
     1、SPI 发送接收数据进行 CRC 校验
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
          2、SPI1、SPI2 同时收发数据，传输完成后，发送 CRC 数据，检查数据和 CRC 值，
               查看 TransferStatus1 和 TransferStatus2 状态为 PASSED，再查看 CRC 值；
4、注意事项
     无

1. Function description
    1. SPI sends and receives data for CRC check
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
        2. SPI1, SPI2 send and receive data at the same time, after the transmission is completed, send CRC data, check the data and CRC value,
           Check that the status of TransferStatus1 and TransferStatus2 is PASSED, and then check the CRC value;
4. Matters needing attention
    No