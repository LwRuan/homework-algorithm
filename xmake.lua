set_xmakever("2.5.6")
add_rules("mode.debug", "mode.release")
set_languages("cxx14")

option("name")
    set_default("helloworld")
    set_showmenu(true)

target("test")
    set_kind("binary")
    add_options("name")
    add_files("$(name).cpp")
    

