this is base on twitcurl(http://code.google.com/p/twitcurl/)

You need to adding libcurl to Xcode’s linker settings.
Targets -> Build Settings -> Linking -> Other Linker Flags
add this : -L/usr/lib -lcurl -lssl -lcrypto -lz
