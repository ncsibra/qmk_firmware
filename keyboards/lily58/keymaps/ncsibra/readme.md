Need to hack because of an Elite-C v3 issue.  
Only necessary until Lily58 not support split common code. 
https://old.reddit.com/r/olkb/comments/dqhg9z/help_with_split_board_using_elite_c_v3_slave_side/f66gpzh/

"in keyboards/lily58/rev1/split_util.c modify thus: bool has_usb(void) { return false; } & flash that to the slave."

To flash the halves use:

```
#left side
make lily58:ncsibra:dfu-split-left
#right side, with Elite-C v3 issue fix
make lily58:ncsibra:dfu-split-right ELITE_C_SPLIT_RIGHT=yes
```
