# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Henrique\Documents\PSoC Creator\henriqueluana\ex3.3.cydsn\ex3.3.cyprj
# Date: Sat, 01 Oct 2022 01:27:22 GMT
#set_units -time ns
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]


# Component constraints for C:\Users\Henrique\Documents\PSoC Creator\henriqueluana\ex3.3.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Henrique\Documents\PSoC Creator\henriqueluana\ex3.3.cydsn\ex3.3.cyprj
# Date: Sat, 01 Oct 2022 01:27:21 GMT