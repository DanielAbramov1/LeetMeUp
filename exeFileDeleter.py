import os

def delete_exe_files():
    try:
        # Get the directory name where the script is located
        script_dir = os.path.dirname(os.path.abspath(__file__))

        # Generate the full path to the directory
        full_path = os.path.join(script_dir, '')

        # Change to the specified directory
        os.chdir(full_path)

        # Get a list of all files in the directory
        files = os.listdir()

        # Iterate through the files and delete .exe files
        for file in files:
            if file.endswith(".exe"):
                os.remove(file)
                print(f"Deleted {file}")

        print("Deletion completed.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Call the function to delete .exe files in the specified directory
delete_exe_files()