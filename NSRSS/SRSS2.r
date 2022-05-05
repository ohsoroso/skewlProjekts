library(dplyr)
library(plotly)

# read and print data
data <- read.csv("C:/Users/notfu/Documents/GitHub/SkewlProjekts/NSRSS/sr_ss_clean.csv",
                 stringsAsFactors=FALSE,
                 sep =",")

# select temperature and humidity and remove empty cells
colnames(data) <- c("Dates", "Sunrise", "Sunset")

plotColors <- c("darkgreen", "orange")
pAxisSpacer <- 0.07

plot <- plot_ly(data, x = data$Dates) %>%
  add_lines(data, y = data$Sunrise, 
            type="scatter",
            mode="lines",
            name='Sunrise',
            yaxis = 'y1', 
            line = list(color = plotColors[1], width = 1)
  ) %>%
  add_lines(data, y = data$Sunset, 
            type="scatter",
            mode="lines",
            name='Sunset',
            yaxis='y2', 
            line = list(color = plotColors[2], width = 1)
  ) %>% 
  layout(
    xaxis = list(title = "Date & Time", 
                 domain = c(pAxisSpacer*3, 1), 
                 type = "date",
                 range = dateRange, 
                 ticks='outside', 
                 zeroline=TRUE, 
                 showline = T),
    yaxis = list(title = 'Sun', 
                 side = "left", 
                 color = plotColors[1], 
                 range = c(minyaxis1,maxyaxis1), 
                 ticks='outside', 
                 dtick = 2, 
                 tick0 = minyaxis1, 
                 tickmode = "linear",
                 position = 0,
                 anchor = 'free', 
                 zeroline = F, 
                 showline = T),
    yaxis2 = list(title = 'Other Sun', 
                  side = "left",
                  color = plotColors[2],
                  range = c(minyaxis2,maxyaxis2), 
                  ticks = 'outside', 
                  dtick = 10, 
                  tick0 = minyaxis2, 
                  tickmode = "linear", 
                  position = pAxisSpacer, 
                  overlaying = "y",
                  anchor = 'free',
                  zeroline=F, 
                  showline = T),
    legend = list(x=pAxisSpacer*3.5, y= 1), 
    showlegend = T,
    title = list(text = "Ploty plot with multiple y axis")
  )
plot