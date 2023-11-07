1、功能说明
     1、SPI 单线中断发送和接收数据
2、使用环境
     软件开发环境：KEIL MDK-ARM 5.30.0.0
     硬件环境：      基于N32G031CL-STB V1.0开发 
3、使用说明
     系统配置：
         1、SystemClock：48MHz
         2、GPIO：SPI1: SCK--PA5、 MOSI--PA7
                         SPI2: SCK--PB13、MISO--PB14
         3、中断：SPI1 中断入口函数 SPI1_IRQHandler，SPI2 中断入口函数 SPI2_IRQHandler

     使用方法：
         1、编译后下载程序复位运行；
         2、SPI1 有数据需要发送时进入 SPI1_IRQHandler 中断函数发送，SPI2 有数据需要接收时进入 SPI2_IRQHandler中断函数接收，
              数据传输完成后，查看 TransferStatus 状态为 PASSED；
4、注意事项
    “单线”数据线在主设备端为MOSI引脚，在从设备端为MISO引脚

1. Function description
    1. SPI single-wire interrupt send and receive data
2. Use environment
    Software development environment: KEIL MDK-ARM 5.30.0.0
    Hardware Environment: Developed based on N32G031CL-STB V1.0
3. Instructions for use
    System Configuration;
        1. SystemClock：48MHz
        2. GPIO：SPI1: SCK--PA5,  MOSI--PA7
                       SPI2: SCK--PB13, MISO--PB14
        3. Interrupt: SPI1 interrupt entry function SPI1_IRQHandler, SPI2 interrupt entry function SPI2_IRQHandler
    Instructions:
        1. After compiling, download the program to reset and run;
        2. When SPI1 has data to send, it enters the SPI1_IRQHandler interrupt function to send, and when SPI2 has data to receive,
            it enters the SPI2_IRQHandler interrupt function to receive. After the data transmission is completed, check the TransferStatus status as PASSED;
4. Matters needing attention
    The "single wire" data lines are MOSI pins on the master side and MISO pins on the slave side