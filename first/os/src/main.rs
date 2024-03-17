#![no_std]
#![no_main]
#![feature(panic_info_message)]

mod sbi;
mod console;
mod lang_items;


#[no_mangle]
pub fn rust_main() -> ! {
    clear_bss();
    println!("Hello,world!");
    panic!("Shutdown machine!");
}

fn clear_bss() {
    extern "C" {
        fn sbss();
        fn ebss();
    }
    (sbss as usize..ebss as usize).for_each(|a|{
        unsafe { (a as *mut u8).write_volatile(0)}
    });
}
