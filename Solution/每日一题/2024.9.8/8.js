var clearDigits = function(s) {
    let res = [];
    for (let c of s){
        if (c >= '0' && c <= '9') {
            res.pop();
        } else {
            res.push(c);
        }
    }
    return res.join('');
};

