bin_PROGRAMS = khusba
INCLUDES = $(all_includes)
khusba_LDFLAGS = $(all_libraries) $(KDE_RPATH)
khusba_LDADD = $(LIB_KIO)
khusba_SOURCES = main.cpp khusba.cpp khusba.skel traywin.cpp syslauncher.cpp \
	khpopoup.ui


noinst_HEADERS = khusba.h traywin.h syslauncher.h

METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/khusba.pot

uconf_DATA = z99_zkhusba.rules
uconfdir = /etc/udev/rules.d/
service_DATA = khusba.desktop 
servicedir = $(kde_servicesdir)
bin_SCRIPTS = advisor khusba_send khusba_info khusba_usb_list usb_analyze \
	khusba_send_pci khusba_pci_list khusba_send_usb pci_analyze
pkgdata_SCRIPTS = usb_analyze.kmdr khusba_pci.kmdr

applnkdir=$(kde_appsdir)/Utilities/
applnk_DATA = khusba_usb.desktop khusba_pci.desktop
iconsdir = @kde_icondir@
icons_DATA=khusba_icon.png
