draw_chessboard() {
	local rows=8
	local cols=8
	black_square="\e[47m \e[0m"
	white_square="\e[40m \e[0m"

	for((i=1; i <= rows; i++)); do
		for((j = 1; j <= cols; j++)); do
			if (( (i + j) % 2 == 0 )); then
				printf "$black_square" # Black squares
			else
				printf "$white_square"  # White squares
			fi
		done
		
		printf "\n"
	done
}
draw_chessboard

