# invoke SourceDir generated makefile for app.pem3
app.pem3: .libraries,app.pem3
.libraries,app.pem3: package/cfg/app_pem3.xdl
	$(MAKE) -f C:\Users\gausp\workspace_v9_2\sensor_CC1350_LAUNCHXL_tirtos_ccs/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\gausp\workspace_v9_2\sensor_CC1350_LAUNCHXL_tirtos_ccs/src/makefile.libs clean

