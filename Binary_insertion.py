def binaryInsertion(arr, val):
    l = 0
    r = len(arr)
    for i in range(len(arr)):
        mid = (l+r)//2
        if arr[mid] == val:
            arr.insert(mid,val)
            return arr
        elif arr[mid] < val:
            l = mid
        else:
            r = mid
    arr.insert(r,val)
#     print("left",l,"right",r)
    return arr

print(binaryInsertion([4,8,87,99],4))