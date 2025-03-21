// Hai đặc điểm quan trọng của một hàm băm hiệu quả là:

// Phân phối đồng đều (Giảm thiểu va chạm)
// Hàm băm cần phân tán các khóa (keys) một cách đồng đều trên bảng băm, giúp hạn chế tình trạng va chạm (collision), tức là nhiều khóa cùng ánh xạ vào một vị trí. Nếu phân phối không đều, các giá trị băm có thể bị tập trung tại một số vị trí nhất định (clustering), làm giảm hiệu suất tra cứu.

// Tính xác định (Nhất quán)
// Hàm băm phải luôn tạo ra cùng một giá trị băm khi nhận cùng một đầu vào. Điều này đảm bảo tính nhất quán trong các thao tác tìm kiếm, chèn và xóa. Nếu một đầu vào lại cho ra giá trị băm khác nhau ở các lần tính toán, việc truy xuất dữ liệu sẽ bị ảnh hưởng. 