# CS2 128tick
Simple server mod to change tickrate to 128 in CS2.


## Installation

Create a folder structure like this in your server installation:

Counter-Strike Global Offensive\game\csgo\\**addons\128tick\bin\win64**.

Put server.dll from `windows.zip` in `addons\128tick\bin\win64`.

Open `Counter-Strike Global Offensive\game\csgo\gameinfo.gi`. Put `Game	csgo/addons/128tick` into SearchPaths like so:
```
	FileSystem
	{
		SearchPaths
		{
			Game_LowViolence	csgo_lv // Perfect World content override
			
			Game	csgo/addons/128tick
			Game	csgo
			Game	csgo_imported
			Game	csgo_core
			Game	core

			Mod		csgo
			Mod		csgo_imported
			Mod		csgo_core

			AddonRoot			csgo_addons

			LayeredGameRoot		"../game_otherplatforms/etc" [$MOBILE || $ETC_TEXTURES] //Some platforms do not support DXT compression. ETC is a well-supported alternative.
			LayeredGameRoot		"../game_otherplatforms/low_bitrate" [$MOBILE]
		}

		"UserSettingsPathID"	"USRLOCAL"
		"UserSettingsFileEx"	"cs2_"
	}
```

You're done!
