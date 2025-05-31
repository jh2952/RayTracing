workspace "RayTracingInOneWeekend"
    architecture "x64"
    configurations { "Debug", "Release" }
    startproject "Application"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "Application"

newaction {
    trigger = "clean",
    description = "Remove all binaries and intermediate binaries and visual studio files",
    execute = function()
        print("Removing Binaries")
        os.rmdir("./bin")
        print("Removing Intermediate Binaries")
        os.rmdir("./bin-int")
        print("Removing Project Files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}