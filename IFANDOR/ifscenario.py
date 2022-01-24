def ticketTime(*input):
  if season == (rainySeason) and (hurricaneSeason) and springBreak or (deal == "Yes"):
    print("Time to get those tickets !!!.")
  elif season != (rainySeason) and (hurricaneSeason) and springBreak or (deal == "No"):
    print("Time to get those tickets !!!.")
  else:
    print("Sorry maybe next time :(")
    
rainySeason = ["May", "June", "July", "August", "September", "October", "November"]
hurricaneSeason = ["June", "July", "August", "September", "October", "November"]
springBreak = ["Feburary", "March", "April"]
season = input("What month is it?")
deal = input("Are tickets on sale?")
ticketTime(season, deal)