# Build application in Windows by cmake

$Env:PATH += ";C:\Users\Forde\Downloads\cmake-4.3.3-windows-x86_64\bin"
$BUILD_DIR = "$PSScriptRoot\Debug"

cmake -S $PSScriptRoot -B ${BUILD_DIR} -G "Visual Studio 18 2026" -A x64
