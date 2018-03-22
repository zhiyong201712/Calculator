[Setup]
AppName=Calculator
AppVersion=1.5
DefaultDirName={pf}\Calculator
DefaultGroupName=Calculator
UninstallDisplayIcon={app}\Calculator.exe
Compression=lzma2
SolidCompression=yes
OutputBaseFilename=CalculatorSetup

[Files]
Source: "Calculator.exe"; DestDir: "{app}"

[Icons]
Name: "{group}\Calculator"; Filename: "{app}\Calculator.exe"