def omt(size):
    # since the results on each side of the diagonal match, 
    # depending on the system, we can optimize by removing calculations (CPU time) and increasing memory usage
    # by calculating half of the table and storing it in a temporary array and then printing out the entire table
    optimized_table = []
    for i in xrange (1,  size+1):
        row = []
        # let's store all of the rows and half of the columns
        for j in xrange (1, i+1):
            row.append(i*j)
        optimized_table.append(row)

    # we should now have the bottom-left half of our table filled out
    
    # print the final multiplication table    
    for i in xrange (0, size):
        row = []
        for j in xrange (0, size):
            if (j > i):
                row.append(optimized_table[j][i])
            else:
                row.append(optimized_table[i][j])
        print row
