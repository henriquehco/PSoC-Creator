# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Henrique\Documents\PSoC Creator\LAB7_3_2_2_PWM\LAB7_3_2_2_PWM.cydsn\LAB7_3_2_2_PWM.cyprj
# Date: Sat, 08 Oct 2022 00:29:04 GMT
#set_units -time ns
create_clock -name {Clock(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFClk} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySysClk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]


# Component constraints for C:\Users\Henrique\Documents\PSoC Creator\LAB7_3_2_2_PWM\LAB7_3_2_2_PWM.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Henrique\Documents\PSoC Creator\LAB7_3_2_2_PWM\LAB7_3_2_2_PWM.cydsn\LAB7_3_2_2_PWM.cyprj
# Date: Sat, 08 Oct 2022 00:29:03 GMT
