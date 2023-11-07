1、功能说明

    该测例演示了LPUART与USARTz间通过中断实现的基础通信。USARTz可以
是USART1。
    LPUART发送TxBuffer1数据至USARTz，USARTz接收数据存至RxBuffer2。同时，
USARTz发送TxBuffer2数据至LPUART，LPUART接收数据存至RxBuffer1。
    随后，分别比较两组接收数据与发送数据，比较结果存入TransferStatus1变量
和TransferStatus2变量。


2、使用环境

    软件开发环境：KEIL MDK-ARM Professional Version 5.26.2.0

    硬件环境：最小系统板N32G031C8L7-STB V1.0


3、使用说明
	
    系统时钟配置如下：
    - 时钟源 = HSI + PLL
    - 系统时钟 = 48MHz
    
    LPUART配置如下：
    - 波特率 = 115200 baud
    - 字长 = 8数据位（固定）
    - 1停止位（固定）
    - 校验控制禁用
    - 硬件流控制禁用（RTS和CTS信号）
    - 接收器和发送器使能
    
    USART配置如下：
    - 波特率 = 115200 baud
    - 字长 = 8数据位
    - 1停止位
    - 校验控制禁用
    - 硬件流控制禁用（RTS和CTS信号）
    - 接收器和发送器使能
    
    LPUART及USART引脚连接如下：
    - LPUART_Tx.PA1   <------->   USART1_Rx.PA10
    - LPUART_Rx.PA0   <------->   USART1_Tx.PA9

    
    测试步骤与现象：
    - Demo在KEIL环境下编译后，下载至MCU
    - 复位运行，依次查看变量TransferStatus1和TransferStatus2，其中，
      PASSED为测试通过，FAILED为测试异常


4、注意事项

    需先将开发板NS-LINK的MCU_TX和MCU_RX跳线帽断开

1. Function description

    This test example demonstrates the basic communication between LPUART and USARTz through interrupts. 
USARTz can be USART1.
     LPUART sends TxBuffer1 data to USARTz, and USARTz receives data to RxBuffer2. At the same time, USARTz 
sends TxBuffer2 data to LPUART, and LPUART receives data to RxBuffer1.
     Subsequently, the two groups of received data and sent data are compared respectively, and the comparison 
results are stored in the TransferStatus1 variable and the TransferStatus2 variable.


2. Use environment

    Software development environment: KEIL MDK-ARM Professional Version 5.26.2.0

    Hardware environment: minimum system board N32G031C8L7-STB V1.0


3. Instructions for use

    The system clock configuration is as follows:
    -Clock source = HSI + PLL
    -System clock = 48MHz
    
    The LPUART configuration is as follows:
    -Baud rate = 115200 baud
    -Word length = 8 data bits (fixed)
    -1 stop bit (fixed)
    -Verification control disabled
    -Hardware flow control disabled (RTS and CTS signals)
    -Receiver and transmitter enable
    
    The USART configuration is as follows:
    -Baud rate = 115200 baud
    -Word length = 8 data bits
    -1 stop bit
    -Verification control disabled
    -Hardware flow control disabled (RTS and CTS signals)
    -Receiver and transmitter enable
    
    The LPUART and USART pin connections are as follows:
    -LPUART_Tx.PA1 <-------> USART1_Rx.PA10
    -LPUART_Rx.PA0 <-------> USART1_Tx.PA9

    
    Test steps and phenomena:
    -After the Demo is compiled in the KEIL environment, download it to the MCU
    -Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, among them,
      PASSED means the test passed, FAILED means the test is abnormal


4. Matters needing attention

    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first