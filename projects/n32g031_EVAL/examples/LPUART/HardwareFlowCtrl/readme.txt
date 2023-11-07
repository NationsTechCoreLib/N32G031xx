1、功能说明

    该测例演示了LPUART与USARTz间使用硬件流控制的基础通信。USARTz
可以是USART1。
    首先，LPUART利用CTS发送TxBuffer1数据，USARTz利用RTS接收
数据，存至RxBuffer2；随后，USARTz利用CTS发送TxBuffer2数据，LPUART
利用RTS接收数据，存至RxBuffer1。
    随后，比较接收数据与发送数据，比较结果分别存入变量TransferStatus1
和TransferStatus2。


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
    - CTS和RTS硬件流控制使能
    - 接收器和发送器使能
   
    USART配置如下：
    - 波特率 = 115200 baud
    - 字长 = 8数据位
    - 1停止位
    - 校验控制禁用
    - CTS和RTS硬件流控制使能）
    - 接收器和发送器使能
    
    
    LPUART及USART引脚连接如下：    
    - LPUART_Tx.PA1      <------->   USART1_Rx.PA10
    - LPUART_Rx.PA0      <------->   USART1_Tx.PA9
    - LPUART_CTS.PA6    <------->   USART1_RTS.PA12
    - LPUART_RTS.PA15   <------->   USART1_CTS.PA8  

    
    测试步骤与现象：
    - Demo在KEIL环境下编译后，下载至MCU
    - 复位运行，依次查看变量TransferStatus1和TransferStatus2，其中，
      PASSED为测试通过，FAILED为测试异常


4、注意事项

    需先将开发板NS-LINK的MCU_TX和MCU_RX跳线帽断开

1. Function description

    This test example demonstrates the basic communication between LPUART and USARTz using hardware flow control. USARTz can be USART1.
     First, LPUART uses CTS to send TxBuffer1 data, USARTz uses RTS to receive data and stores it in RxBuffer2; then, USARTz uses CTS to send 
TxBuffer2 data, and LPUART uses RTS to receive data and stores it in RxBuffer1.
     Then, compare the received data with the sent data, and the comparison results are stored in the variables TransferStatus1 and TransferStatus2 respectively.


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
    -CTS and RTS hardware flow control enable
    -Receiver and transmitter enable
   
    The USART configuration is as follows:
    -Baud rate = 115200 baud
    -Word length = 8 data bits
    -1 stop bit
    -Verification control disabled
    -CTS and RTS hardware flow control enable)
    -Receiver and transmitter enable
    
    
    The LPUART and USART pin connections are as follows:
    -LPUART_Tx.PA1 <-------> USART1_Rx.PA10
    -LPUART_Rx.PA0 <-------> USART1_Tx.PA9
    -LPUART_CTS.PA6 <-------> USART1_RTS.PA12
    -LPUART_RTS.PA15 <-------> USART1_CTS.PA8

    
    Test steps and phenomena:
    -After the Demo is compiled in the KEIL environment, download it to the MCU
    -Reset operation, check the variables TransferStatus1 and TransferStatus2 in turn, among them,
      PASSED means the test passed, FAILED means the test is abnormal


4. Matters needing attention

    the MCU_TX and MCU_RX jumper cap of the development board NS-LINK needs to be disconnected first