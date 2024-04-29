@echo off
setlocal EnableDelayedExpansion
::
:: Вид сборки / суффикс в названии каталога сборки
::
:: "Ninja" / "ninja"
:: "Visual Studio 17 2022" / "visual_studio"
::
set BUILD_TYPE="Ninja"
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

set arr[0].file=run_bubble_sort.bat
set arr[1].file=run_comb_bubble_sort.bat
set arr[2].file=run_obuchaika.bat
set arr[3].file=run_long_number_tests.bat

set arr[0].folder=bubble_sort
set arr[1].folder=comb_bubble_sort
set arr[2].folder=obuchaika
set arr[3].folder=scl\test\long_number

for /L %%i in (0,1,4) do ( 
	if not exist .\!arr[%%i].folder!\!arr[%%i].file! (
		copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
	)
)

if not exist .\run_tests.bat copy ..\run_tests.bat .