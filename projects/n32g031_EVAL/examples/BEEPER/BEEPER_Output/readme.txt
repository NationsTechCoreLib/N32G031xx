1、功能说明
    此例程展示蜂鸣器模块的用法。
    
2、使用环境

    软件开发环境：KEIL MDK-ARM 5.26
    硬件环境：       N32G031C8L7-STB V1.0

3、使用说明
    1、时钟源：HSE+PLL
    2、主时钟：48MHz
    3、输出端口：
	   PA6		AF_PP
	   PA7		AF_PP

    4、测试步骤与现象
       a，编译下载代码复位运行
       b，用示波器查看波形，验证结果
	
4、注意事项
    1、PA6与PA7的波形互补
    2、支持进入LPRUN模式，此时输出频率为pclk1的4分频值
    3、APB时钟频率选择寄存器位（freq_sel）的值根据主频而定，起到输出波形不至于失真的效果

1. Function description
    This example shows the usage of the buzzer module.
    
2. Use environment
    Software  environment: KEIL MDK-ARM 5.26
    Hardware environment: N32G031C8L7-STB V1.0

3. Instructions for use
     1. Clock source: HSE+PLL
     2. Main clock: 48MHz
     3. Output port：
        PA6		AF_PP
        PA7		AF_PP

     4. Test steps and phenomenon
        a. Compile and download the code to reset and run.
        b. View the waveform with an oscilloscope to verify the results.

4. Matters needing attention
     1. The waveforms of PA6 and PA7 are complementary.
     2. Support entering LPRUN mode, the output frequency is the 4 frequency division value of pclk1 at this time.
     3. The value of the APB clock frequency selection register bit (freq_sel) is determined according to the main frequency, 
        so that the output waveform will not be distorted.