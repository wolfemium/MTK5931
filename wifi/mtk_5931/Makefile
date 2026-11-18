# MediaTek MT5931 SDIO Wi-Fi, station mode via cfg80211.
# Ported from the MediaTek/Rockchip vendor tree (2013) to mainline kernels for
# the Rikomagic MK802 IV. Wi-Fi Direct, BT-over-Wi-Fi, WAPI and wireless
# extensions are not built.

ccflags-y += -DLINUX -DMT5931 -D_HIF_SDIO=1 -DDBG=0
ccflags-y += -DCFG_SUPPORT_WAPI=0 -DCFG_SUPPORT_XLOG=0 -DCFG_SUPPORT_AEE=0
ccflags-y += -I$(src)/os -I$(src)/os/linux/include -I$(src)/os/linux/hif/sdio/include
ccflags-y += -I$(src)/include -I$(src)/include/nic -I$(src)/include/mgmt

obj-m += mt5931.o

mt5931-y := \
	common/dump.o common/wlan_lib.o common/wlan_oid.o \
	nic/nic.o nic/nic_tx.o nic/nic_rx.o nic/nic_pwr_mgt.o nic/cmd_buf.o \
	nic/que_mgt.o nic/nic_cmd_event.o \
	os/linux/gl_init.o os/linux/gl_kal.o os/linux/gl_rst.o \
	os/linux/gl_cfg80211.o os/linux/platform.o \
	os/linux/hif/sdio/arm.o os/linux/hif/sdio/sdio.o \
	mgmt/ais_fsm.o mgmt/aaa_fsm.o mgmt/assoc.o mgmt/auth.o mgmt/bss.o \
	mgmt/cnm.o mgmt/cnm_timer.o mgmt/cnm_mem.o mgmt/hem_mbox.o mgmt/mib.o \
	mgmt/privacy.o mgmt/rate.o mgmt/rlm.o mgmt/rlm_domain.o mgmt/rlm_obss.o \
	mgmt/rlm_protection.o mgmt/rsn.o mgmt/saa_fsm.o mgmt/scan.o \
	mgmt/scan_fsm.o mgmt/sec_fsm.o mgmt/swcr.o mgmt/roaming_fsm.o
