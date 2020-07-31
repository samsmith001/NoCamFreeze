-- premake5.lua
workspace "NoCamFreeze"
   configurations { "Debug", "Release" }

project "NoCamFreeze"
   kind "SharedLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "**.h", "**.cpp" }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"
      targetextension ".asi"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"
      targetextension ".asi"