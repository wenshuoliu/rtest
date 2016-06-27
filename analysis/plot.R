#This file is to test various plot functions

#ggplot2

library(ggplot2)
library(ggrepel)

head(mtcars)

ggplot(mtcars, aes(x = wt, y = mpg))+geom_point(aes(color = hp), size = 2) + geom_smooth() +
  geom_text_repel(aes(label = gear), size = 6)

ggplot(mtcars, aes(x = hp, y = qsec)) + geom_point(aes(color = wt), size = 2) +
  geom_text_repel(aes(label = gear), size = 6)
