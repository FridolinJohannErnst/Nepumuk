workspace "Nepumuk"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Nepumuk"
	location "Nepumuk"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{	
			"NK_PLATFORM_WINDOWS",
			"NK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "NK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "NK_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nepumuk/vendor/spdlog/include",
		"Nepumuk/src"
	}


	links
	{
		"Nepumuk"
	}

	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "On"
		systemversion "latest"
		
		defines 
		{	
			"NK_PLATFORM_WINDOWS"
		}

	buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "NK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NK_RELEASE"
		symbols "On"

	filter "configurations:Dist"
		defines "NK_DIST"
		symbols "On"

	filter { "system:windows", "configurations:Release"}
		buildoptions "/MT"