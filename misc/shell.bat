@echo off
subst p: C:\Projects
p:
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
set path=p:\handmade-hero\misc;%path%
set path=p:\handmade-hero\code;%path%
cd handmade-hero
code .