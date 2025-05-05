source [find interface/kitprog3.cfg]

transport select swd


source [find target/traveo2_be_4m.cfg]
${TARGET}.cm4 configure -rtos auto -rtos-wipe-on-reset-halt 1
traveo2 sflash_restrictions 1
