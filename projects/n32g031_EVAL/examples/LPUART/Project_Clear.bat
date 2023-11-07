@echo on
rem  Init project clear ....
pause

::延时
::ping -n 30 127.0.0.1 > null

::for Keil
for /r %~dp0 %%d in (MDK-ARM) do (
  
    del "%%d\*.scvd"
    del "%%d\*.uvguix.*"
 
    rd /s /q "%%d\Objects"
    rd /s /q "%%d\Listings"
    rd /s /q "%%d\bin"

)

::for IAR
for /r %~dp0 %%d in (EWARM) do (
    del "%%d\*.ewt"
    del "%%d\*.uvoptx"
    del "%%d\*.uvprojx"
    del "%%d\ConvertToIARReport.txt"

    rd /s /q "%%d\settings"
    rd /s /q "%%d\Debug"

)
rem Project cleared done
pause