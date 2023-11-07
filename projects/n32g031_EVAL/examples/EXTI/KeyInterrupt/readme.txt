1、功能说明

    此例程展示通过外部触发中断，控制 LED 闪烁


2、使用环境

    /* 软件开发环境：当前工程使用的软件工具名称及版本号 */
    IDE工具：KEIL MDK-ARM 5.21.1.0
      
    /* 硬件环境：工程对应的开发硬件平台 */
    开发板：N32G031CL-STB V1.0     

3、使用说明

    /* 描述相关模块配置方法；例如:时钟，I/O等 */
    SystemClock：48MHz
    GPIO：PA5 选择作为外部中断入口，PB7 控制 LED(PD3) 闪烁


    /* 描述Demo的测试步骤和现象 */
    1.编译后下载程序复位运行；
    2.按下松开 KEY2 按键，LED 闪烁；


4、注意事项
    无

1. Function description

    This example shows how to control LED blinking by externally triggering an interrupt.
    

2. Use environment

    Software development environment:  //the name and version number of the software tool used in the current project.
        IDE tool: KEIL MDK-ARM 5.21.1.0
    
    Hardware environment:  //The development hardware platform corresponding to the project.
        Development Board: N32G031CL-STB V1.0


3. Instructions for use

     //Describe related module configuration methods; for example, clock, I/O, etc.
     1. SystemClock: 48MHz
     2. GPIO：PA5 is selected as the external interrupt entry, PB7 controls the LED (PD3) to flash.

     //Describe the test steps and phenomena of the Demo
     1. Compile and download the code to reset and run.
     2. Press and release the KEY2 button,then the LED will flash.

4. Matters needing attention
     None