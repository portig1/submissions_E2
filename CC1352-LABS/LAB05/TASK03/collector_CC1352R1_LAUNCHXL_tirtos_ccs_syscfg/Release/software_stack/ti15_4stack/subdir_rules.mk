################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
software_stack/ti15_4stack/%.obj: ../software_stack/ti15_4stack/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti_ccs_9_2/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/bin/armcl" --cmd_file="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/application/defines/collector.opts"  -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O4 --opt_for_speed=0 --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/Release" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/application/collector" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/application" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/services" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/hal/assert" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/hal/appasrt" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/hal/crypto" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/hal/platform" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/hal/rf" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/mac/high_level" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/mac/low_level" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/software_stack/ti15_4stack/osal_port" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/apps" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/boards" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/osal_port" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/util" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/inc" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/stack/src" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/stack/tirtos/inc" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/common/heapmgr" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/services/saddr" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/services/sdata" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/assert" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/appasrt" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/crypto" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/platform" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/hal/rf" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/fh" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/high_level" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/inc" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/rom" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/inc/cc13xx" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/low_level/cc13xx" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/tracer" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/ti154stack/apps/collector" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/devices/cc13x2_cc26x2" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/devices/cc13x2_cc26x2/inc" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/devices/cc13x2_cc26x2/driverlib" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/common/nv" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/common/cui" --include_path="C:/ti/simplelink_cc13x2_26x2_sdk_3_30_00_03/source/ti/posix/ccs" --include_path="C:/ti_ccs_9_2/ccs/tools/compiler/ti-cgt-arm_18.12.3.LTS/include" --define=TIMAC_ROM_IMAGE_BUILD --define=Board_EXCLUDE_NVS_EXTERNAL_FLASH --define=DeviceFamily_CC13X2 -g --c99 --plain_char=unsigned --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --embedded_constants=on --unaligned_access=on --enum_type=packed --wchar_t=16 --common=on --fp_reassoc=off --sat_reassoc=off --preproc_with_compile --preproc_dependency="software_stack/ti15_4stack/$(basename $(<F)).d_raw" --include_path="C:/Users/gausp/workspace_v9_2/collector_CC1352R1_LAUNCHXL_tirtos_ccs_syscfg/Release/syscfg" --obj_directory="software_stack/ti15_4stack" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


