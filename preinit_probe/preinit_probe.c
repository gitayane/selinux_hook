#include <linux/kernel.h>
#include <linux/printk.h>
#include <kpmodule.h>

KPM_NAME("preinit_probe");
KPM_VERSION("0.1.0");
KPM_LICENSE("GPL v2");
KPM_AUTHOR("gitayane");
KPM_DESCRIPTION("Minimal PRE_KERNEL_INIT KPM loader probe");

static long init(const char *args, const char *event, void *reserved)
{
    printk("[preinit_probe] KPM_INIT reached event=%s\n",
           event ? event : "(null)");
    return 0;
}

static long exit_(void *reserved)
{
    printk("[preinit_probe] KPM_EXIT\n");
    return 0;
}

KPM_INIT(init);
KPM_EXIT(exit_);
