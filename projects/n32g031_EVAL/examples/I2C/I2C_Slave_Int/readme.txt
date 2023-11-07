1、功能说明

    此例程展示了作为从机使用I2C中断收发数据。   

2、使用环境

   软件开发环境：
        IDE工具：KEIL MDK-ARM 5.21.1.0
    
    硬件环境：
        开发板：N32G031C8L7-STB V1.0


3、使用说明
	
    1、主时钟：48MHz
    2、I2C1 配置：
            SCL   -->  PB6          
            SDA   -->  PB7         
            CLOCK:100KHz
            
    3、USART1配置：
            TX  -->  PA9   
	    RX  -->  PA10           
            波特率：115200
        

    4、测试步骤与现象
        a，跳线连接主机I2C1
        b，编译下载代码复位运行
        c，从串口看打印信息，验证结果

4、注意事项
    1. SCL及SDA必须接上拉;
    2. I2C从机地址不要使用 0xF0

1. Function description

     This example demonstrates the use of I2C interrupts to send and receive data as a slave.

2. Use environment

    Software development environment:
         IDE tool: KEIL MDK-ARM 5.21.1.0
    
     Hardware environment:
         Development board: N32G031C8L7-STB V1.0


3. Instructions for use

     1. Main clock: 48MHz
     2. I2C1 configuration:
             SCL --> PB6
             SDA --> PB7
             CLOCK: 100KHz
            
     3. USART1 configuration:
             TX --> PA9
	     RX --> PA10
             Baud rate: 115200
        

     4. Test steps and phenomena
         a, the jumper wire connects the master I2C1
         b, compile and download the code, reset and run
         c, view the print information from the serial port and verify the result

4. Matters needing attention
     1. SCL and SDA must be pulled up
     2. Do not use 0xF0 as the I2C slave address.