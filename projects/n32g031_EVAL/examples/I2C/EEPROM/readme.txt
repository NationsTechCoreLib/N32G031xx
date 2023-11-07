1、功能说明

    此例程展示了通过I2C模块与外部EEPRON的通信。   

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
            CLOCK:400KHz
            
    3、USART1配置：
            TX  -->  PA9   
            RX  -->  PA10           
            波特率：115200
    
    4、测试使用EEPROM型号:
	    AT24C04（容量4kb）
        

    5、测试步骤与现象
        a，检查EEPROM连接
        b，编译下载代码复位运行
        c，从串口看打印信息，验证结果

4、注意事项
   无

1. Function description

     This example demonstrates the communication with the external EEPRON through the I2C module.

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
             CLOCK: 400KHz
            
     3. USART1 configuration:
             TX --> PA9
             RX --> PA10
             Baud rate: 115200
    
     4. Test using EEPROM model:
            AT24C04 (capacity 4kb)
        

     5. Test steps and phenomena
         a, check the EEPROM connection
         b, compile and download the code, reset and run
         c, view the print information from the serial port and verify the result

4. Matters needing attention
    without