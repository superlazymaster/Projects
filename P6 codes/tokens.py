while True:
    try:
        x = input()
        list = x.split(" ")
        if "," in list[0]:
            continue
        valid = True
        for i in range(1, len(list)):
            if list[i].count(",")!=1 and i<len(list)-1:
                valid = False
                break
            elif " " in list[i]:
                valid = False
                break
            elif i == len(list)-1:
                if list[i].count(",")>0:
                    valid = False
            else:
                list[i] = list[i].replace(",", "")
        if valid:
            output_string = " ".join(list)
            print(output_string)
            

    except EOFError:
        break