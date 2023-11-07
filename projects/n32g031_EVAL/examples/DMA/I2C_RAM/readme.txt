1、功能说明

    此例程提供了一种DMA用法，用于在I2C外设与RAM之间传输数据。  

2、使用环境

    软件开发环境：
        IDE工具：KEIL MDK-ARM 5.26
    
    硬件环境：
        开发板 N32G031C8L7-STB V1.0


3、使用说明
	
    1、时钟源：HSE+PLL
    2、主时钟：48MHz
    3、DMA通道：DMA_CH5，DMA_CH6
    4、I2C1 配置：
            SCL   -->  PB6
            SDA   -->  PB7
            ADDR：0x30(7bit)
            CLOCK：100K
    
    5、I2C2 配置：
            SCL   -->  PA6
            SDA   -->  PA7
            ADDR：0x30(7bit)
            CLOCK：100K
    
    6、USART1配置：
            TX  -->  PA9
            波特率：115200
            数据位：8bit
            停止位：1bit
            无校验

    7、测试步骤与现象
        a，编译下载代码复位运行
        b，从串口看打印信息，验证结果

4、注意事项
    无


1. Function description
    This routine provides a DMA usage for transferring data between I2C peripheral and RAM.

2. Use environment
    Software Development environment:
	IDE tool: KEIL MDK-ARM 5.26
    
    Hardware environment:
	N32G031C8L7-STB V1.0

3. Instructions for use
    1.Clock source: HSE+PLL
    2.Master clock: 48MHz
    3.DMA channels: DMA_CH5, DMA_CH6
    4.I2C1 configuration:
	SCL   -->  PB6
        SDA   -->  PB7
        ADDR：0x30(7bit)
        CLOCK：100K
    5.I2C2 configuration:
        SCL   -->  PA6
        SDA   -->  PA7
        ADDR：0x30(7bit)
        CLOCK：100K    
    6.USART1 configuration:
        TX  -->  PA9
	Baud rate: 115200
	Data bit: 8 bits
	Stop bit: 1bit
	No check            
    7.Test steps and phenomena
	A. Compile download code reset run
	B. View the printed information from the serial port and verify the result

4. Precautions
    None
